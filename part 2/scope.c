#include "scope.h"

int mainFunctions = 0;

void scanTree(node* tree,scope** scope1){
    scope *tmpScope;
    if(tree){
        //If you see func_node - if global scope have many functions
        if(idType(tree->token)==5){
            scanTree(tree->left,scope1);
            if(tree->mid1)
                scanTree(tree->mid1,scope1);
        }
        //for recursive call for function
        if(idType(tree->token)==0){
            if(checkBrotherExist((*scope1)->innerScope,tree->mid1->token)){
                char* error=(char*)malloc(sizeof(char)*100);
                strcpy(error,"Function ");
                strcat(error,tree->mid1->token);
                strcat(error," already declared");
                printError(error);
            }
            //Checks for main
            if(!strcmp(tree->mid1->token,"main")){
            	if(strcmp("void",tree->left->token))
            		printError("main must be void type");
                mainFunctions++;
                //Checks if there us more then 1 main
                if(mainFunctions==2)
                    printError("only 1 main allowed");
                //Checks if main does not have any parameters
                if(tree->mid2)
                    printError("main can not be with parameters");
            }
            //If this is the first inner function
            tmpScope=initScope(tree->mid1->token, 1, tree->left->token);
            scope *tmp = getLastScope((*scope1)->innerScope);
            if(tmp==NULL){ 
                //if the function have parameters
                if(tree->mid2){
                   getVarArry(tree->mid2,0,&(tmpScope->params),NULL,NULL,**scope1);
                }       
                (*scope1)->innerScope=tmpScope; 
                (*scope1)->innerScope->upperScope=(*scope1);   
                scanTree(tree->right, &((*scope1)->innerScope));
            }
            //This is not the first inner function
            else{
                tmp->next = tmpScope;
                tmpScope->upperScope = (*scope1);
                if(tree->mid2){
                   getVarArry(tree->mid2,0,&(tmpScope->params),NULL,NULL,**scope1);
                }
                scanTree(tree->right, &tmpScope);
            }
        }

        //for body
        if(idType(tree->token)==3){
            
            //We have declarations!!
            if(tree->left)
                scanTree(tree->left,scope1);
            //
            if(tree->mid1){
                scanTree(tree->mid1,scope1);
            }
            if(tree->mid2){
                char* retype = (char*)malloc(sizeof(char)*100);

                if(!tree->mid2->left) 
                    strcpy(retype,"void");
                else
                    strcpy(retype,getExprType(*tree->mid2->left,**scope1));

                if(strcmp(retype,getMyFuncReturn(**scope1))){
                    char* error=(char*)malloc(sizeof(char)+50);
                	strcpy(error,"Return '");
                	strcat(error,retype);
                	strcat(error,"' instead of '");
                	strcat(error,getMyFuncReturn(**scope1));
                	strcat(error,"', check your '");
                	strcat(error,(*scope1)->scope_id);
                	strcat(error,"' .");
                	printError(error);
                }    
            }
            else{
                if((*scope1)->isFunction && strcmp((*scope1)->return_type,"void")){
                	char* error=(char*)malloc(sizeof(char)+50);
                	strcpy(error,"Function '");
                	strcat(error,(*scope1)->scope_id);
                	strcat(error,"' must have return statement");
                	printError(error);
                 }
             }
                

        } 

        //for delerations
        if(idType(tree->token)==4){
            //If you see var declerations!!
            if(idType(tree->left->token)==2){
                    if((*scope1)->vars){
                        var* tmp = getLastVar((*scope1)->vars);
                        
                        getVarArry(tree->left,1,&(tmp),tree->left->left->token, (*scope1)->vars,**scope1);
                        scanTree(tree->mid1,scope1);
                    }
                    else{
                        
                        getVarArry(tree->left,1,&((*scope1)->vars),tree->left->left->token, (*scope1)->vars,**scope1);
                        scanTree(tree->mid1,scope1);
                    }     
            }
            //if you see func declerations!!
            else
            {   
                scanTree(tree->left,scope1);
                scanTree(tree->mid1,scope1);
                
            }
        }

        //for statments
        if(idType(tree->token)==6){
            //If we see loops/ifs
            if(idType(tree->left->token)==1){
                //If we see FOR
                if(!strcmp(tree->left->token,"FOR")){
                    CheckStatement(*tree->left->left,**scope1);
                    
                    if(strcmp(getExprType(*(tree->left->mid1),**scope1),"boolean"))
                        printError("Condition must be boolean");
                   
                    CheckStatement(*tree->left->mid2,**scope1);
                }
                //If we not seen FOR 
                else if(strcmp(getExprType(*(tree->left->left),**scope1),"boolean")){
                    printError("Condition must be boolean");
                }

                //If this is the first inner function
                
                tmpScope=initScope(tree->left->token, 0, NULL);
                scope *tmp = getLastScope((*scope1)->innerScope);
                if(tmp==NULL){ 
                    (*scope1)->innerScope=tmpScope; 
                    (*scope1)->innerScope->upperScope=(*scope1); 
                    //if the statment is code block
                    scanTree(tree->left->mid1, &((*scope1)->innerScope));
                    
                }
                //This is not the first inner function
                else{
                    tmp->next = tmpScope;
                    tmpScope->upperScope = (*scope1);
                    scanTree(tree->left->mid1, &tmpScope);
                    
                }
                
                if(!strcmp(tree->left->token,"IF") && tree->left->mid2){
                    	
                    	tmpScope=initScope("ELSE", 0, NULL);
                		scope *tmp = getLastScope((*scope1)->innerScope);
                		tmp->next=tmpScope; 
                		tmpScope->upperScope = (*scope1);
                		scanTree(tree->left->mid2, &tmpScope);

                    }
                //Check if the next node got code block or not
                scanTree(tree->mid1, scope1);
            }

            //if we see body
            else if(idType(tree->left->token)==3){

                tmpScope=initScope(tree->left->token, 0, NULL);
                scope *tmp = getLastScope((*scope1)->innerScope);
                if(tmp==NULL){ 
                    (*scope1)->innerScope=tmpScope; 
                    (*scope1)->innerScope->upperScope=(*scope1); 
                    //if the statment is code block
                    scanTree(tree->left, &((*scope1)->innerScope));
                }
                else{
                    tmp->next = tmpScope;
                    tmpScope->upperScope = (*scope1);
                    scanTree(tree->left, &tmpScope);
                }
                scanTree(tree->mid1, scope1);

            }

            //Else this statment is function call or assigment
            else{   
                
                CheckStatement(*(tree->left),**scope1);
                scanTree(tree->mid1, scope1);
            }
        }


        return;
    }
    
    
}

void printError(char* error){
    printf("%s\n",error);
    exit(1);
}

var* getLastVar(var *array){
    if((array != NULL && array->next == NULL) || array  == NULL )
        return array;
    return getLastVar(array->next);
}

scope* getLastScope(scope *scp){
    if((scp != NULL && scp->next == NULL) || scp  == NULL )
        return scp;
    return getLastScope(scp->next);
}

//type = 0 -> function params
//type = 1 -> scope variables
void getVarArry(node *tree,int type,var** array,char* typeID, var* firstVar, scope scp){
    if(type==0){
        if(*array==NULL){
            (*array)=(var*)malloc(sizeof(var));
            (*array)->id=(char*)malloc(sizeof(char)*100);
            (*array)->type=(char*)malloc(sizeof(char)*100);
            strcpy((*array)->type,tree->mid1->token);
            strcpy((*array)->id,tree->mid1->left->token);
            getVarArry(tree->left,type,array,NULL, NULL,scp);
            return;
        }
        var* temp=(var*)malloc(sizeof(var));
        if(tree){
            temp->id=(char*)malloc(sizeof(char)*100);
            temp->type=(char*)malloc(sizeof(char)*100);
            strcpy(temp->type,tree->mid1->token);
            strcpy(temp->id,tree->mid1->left->token);
            (*array)->next=temp;

            getVarArry(tree->left,type,&temp,NULL,NULL,scp);
        }
    }
    if(type==1){
        var* tmp = firstVar;
        if(*array==NULL){
            (*array)=(var*)malloc(sizeof(var));
            (*array)->id=(char*)malloc(sizeof(char)*100);
            (*array)->type=(char*)malloc(sizeof(char)*100);
            strcpy((*array)->type,typeID);
            strcpy((*array)->id, tree->mid1->left->token);
            if(tree->mid2){
                if((strcmp(getExprType(*tree->mid2->left,scp),"int")))
                    printError("Size of string must be int");    
            }
            getVarArry(tree->mid1->mid1, type, array,typeID, (*array),scp);
            return;
        }
        var* temp=(var*)malloc(sizeof(var));
        if(tree){
            if( idType(tree->token)==2){
                tree=tree->mid1;
            }
            temp->id=(char*)malloc(sizeof(char)*100);
            temp->type=(char*)malloc(sizeof(char)*100); 
            strcpy(temp->type,typeID);
            strcpy(temp->id,tree->left->token);
            if(tree->mid2){
                if((strcmp(getExprType(*tree->mid2->left,scp),"int")))
                    printError("Size of string must be int");    
            }
            if (tmp){
                while(tmp){
                    if (!strcmp(temp->id,tmp->id)){
                        char* error=(char*)malloc(sizeof(char)*100);
                        strcpy(error,"Variable '");
                        strcat(error,temp->id);
                        strcat(error,"' already declared");
                        printError(error);
                    }
                    else tmp = tmp->next;
                }
            }
            (*array)->next=temp;
            getVarArry(tree->mid1, type, &temp,typeID, firstVar,scp);
            return;
        }  
    }
}

// 0 - function
// 1 - if or loops
// 2 - for var declartions
// 3 - for body
// 4 - for declerations
// 5 - for func node for global scope!
int idType(char* id){
    if(!strcmp(id,"FUNCTION"))
        return 0;
    if(!strcmp(id,"IF") || !strcmp(id,"FOR") || !strcmp(id,"WHILE") || !strcmp(id,"DO WHILE"))
        return 1;
    if(!(strcmp(id,"IDS")))
        return 2;
    if(!(strcmp(id,"BODY")))
        return 3;
    if(!(strcmp(id,"DECLARATIONS")))
        return 4;
    if(!(strcmp(id,"FUNC_NODE")))
        return 5;
    if(!(strcmp(id,"STATMENT_NODE")))
        return 6;
    if(!(strcmp(id,"=")))
        return 7;
    if(!strcmp(id,"||")|| !strcmp(id,"&&"))
        return 8;
    if( !strcmp(id,">") || !strcmp(id,">=") || !strcmp(id,"<")|| !strcmp(id,"<="))
        return 9;
    if(!(strcmp(id,"!")))
        return 10;
    if(!strcmp(id,"/") || !strcmp(id,"+") || !strcmp(id,"*") || !strcmp(id,"-"))
        return 11;
    if(!strcmp(id,"&"))
        return 12;
    if(!(strcmp(id,"FUNC CALL")))
        return 13;
    if(!strcmp(id,"!=") || !strcmp(id,"==") )
        return 14;
    if(!(strcmp(id,"ABS")))
        return 15;
    if(!strcmp(id,"^"))
        return 16;
    if(!strcmp(id,"RETURN"))
        return 17;
    if(!strcmp(id,"CHAR VAR"))
        return 18;
    if(!strcmp(id,"STRING VAR"))
        return 19;
    return -1;
    
}

void printSymbolTable(scope* scope,int tab){
    printf("***************************\n");
    printf("Scope Name: %s\n",scope->scope_id);
    if(scope->upperScope)
        printf("UpperScope Name: %s\n",scope->upperScope->scope_id);
    if(scope->next)
        printf("next scope Name: %s\n",scope->next->scope_id);  
    else
         printf("%s have no next :(\n",scope->scope_id);
    if(scope->isFunction==1)
        printf("This is a function!\n");
    else
        printf("Not a function :(\n");
    printParamsOrVars(scope,0,tab);
    printParamsOrVars(scope,1,tab);
    if(scope->return_type)
        printf("Return type: %s\n",scope->return_type);
    else
        printf("No return type :(\n");
    if(scope->innerScope)
        printSymbolTable(scope->innerScope,tab+1);
    if(scope->next)
        printSymbolTable(scope->next,tab+1);
}


//if choose is 0 - print vars else print params :)
void printParamsOrVars(scope* scope,int choose,int tab){
    var* temp;
    if(choose==0){
        if(scope->vars){
            printf("Vars:\n");
            temp=scope->vars;
            while(temp){
                printf("    Var: %s\n",temp->id);
                printf("    Type: %s\n",temp->type);
                temp=temp->next;
            }
        }
        else{
            printf("No vars :(\n");
        }        
    }
    else{
        if(scope->params){
            printf("Params:\n");
            temp=scope->params;
            while(temp){
                printf("    Var: %s\n",temp->id);
                printf("    Type: %s\n",temp->type);
                temp=temp->next;
            }
        }
        else{
            printf("No params :(\n");
        }       
    }
}

scope* initGlobalScope(){
    scope* newscope = (scope*)malloc(sizeof(scope));
    newscope->innerScope=NULL;
    newscope->isFunction=0;
    newscope->next=NULL;
    newscope->params=NULL;
    newscope->return_type=NULL;
    newscope->scope_id=(char*)malloc(sizeof(char)*100);
    strcpy(newscope->scope_id,"GlobalScope");
    newscope->upperScope=NULL;
    newscope->vars = NULL;
    return newscope;
}

//1 for function and 0 for non function
scope* initScope(char* scope_name,int isFunction, char* type){
    scope* newscope = (scope*)malloc(sizeof(scope));
    newscope->innerScope=NULL;
    newscope->isFunction=isFunction;
    newscope->next=NULL;
    newscope->params=NULL;
    if(type){
        newscope->return_type=(char*)malloc(sizeof(char)*100);
        strcpy(newscope->return_type,type);
    }
    else
        newscope->return_type=NULL;
    newscope->scope_id=(char*)malloc(sizeof(char)*100);
    strcpy(newscope->scope_id,scope_name);
    newscope->upperScope=NULL;
    newscope->vars = NULL;
    return newscope;
}

// 0 - not exist
// 1 - already exist!!
int checkBrotherExist(scope* start,char* scopeName){
    scope* tmpScope=start;
    while(tmpScope){
        if(!(strcmp(tmpScope->scope_id,scopeName)))
            return 1;
        else
           tmpScope=tmpScope->next; 
    }
    return 0;
}

void checkMainOnce(){
    if(mainFunctions==0)
        printError("Where is your main?!?!?!");
}

void CheckStatement(node tree,scope scp){
    if(idType(tree.token)==7){
        //the token is '='
        if(tree.left->left){
            if(!strcmp(tree.left->token,"^") || !strcmp(tree.left->token,"&")){
                if(!strcmp(tree.left->token,"&")){
                    printError("Can't assign into adress of variable");
                }
                char* var_type = getExprType(*(tree.left),scp);
                char* expr_type = getExprType(*(tree.mid1),scp);
                if(strcmp(var_type,expr_type))
                    printError("Operator '=' can only be used with identical types");
            }
                
            else{
                if(strcmp(getExprType(*tree.left->left->left,scp),"int")){
                printError("Index must be int");
                }
                if(strcmp(getVarType(scp,tree.left->token),"string"))
                    printError("Index operator must be only used with string variables");
                if(strcmp(getExprType(*tree.mid1,scp),"char")){
                printError("String[] can be assigned only to char variable");
                }
            }
        }
        else{
            if(!strcmp(tree.mid1->token,"NULL")){
            if((strcmp(getVarType(scp,tree.left->token),"intp") && strcmp(getVarType(scp,tree.left->token),"charp")))
                printError("NULL can be assigned only to intp or charp variabels");
            }
            else{
                char* var_type = getVarType(scp,tree.left->token);
                char* expr_type = getExprType(*(tree.mid1),scp);
                if(strcmp(var_type,expr_type))
                    printError("Operator '=' can only be used with identical types");
            }
        }
    }
    else{
        
        checkFunctionCall(*tree.left,scp,getFuncParams(scp,tree.token));
    }
         


}

char* getVarType(scope scp,char* var){
    if(isNumber(var)){
        return "int";
    }  
    if(!strcmp(var,"false") || !strcmp(var,"true"))
        return "boolean";
    
    while(scp.vars!=NULL){
        if(!(strcmp(var,scp.vars->id)))
            return scp.vars->type;
        
        scp.vars = scp.vars->next;
    }
    
    while(scp.params){
    	
    	if(!strcmp(scp.params->id,var))
    		return scp.params->type;
    	
    	scp.params = scp.params->next;
    }
    if(scp.upperScope){
        return getVarType(*(scp.upperScope),var);
    }
    char* error=(char*)malloc(sizeof(char)*100);
    strcpy(error,"Variable '");
    strcat(error,var);
    strcat(error,"' not declared");
    printError(error);
    return NULL;
}

char* getFuncType(scope scp,char* func){
    while(scp.innerScope != NULL){
        if(!strcmp(func,scp.innerScope->scope_id)){
            if(scp.innerScope->isFunction)
                return scp.innerScope->return_type;
        }
        scp.innerScope = scp.innerScope->next;
    }
    if(scp.upperScope){
        return getFuncType(*(scp.upperScope),func);
    }
    char* error=(char*)malloc(sizeof(char)*100);
    strcpy(error,"Function '");
    strcat(error,func);
    strcat(error,"' not declared");
    printError(error);
    return NULL;

}

char* getExprType(node tree,scope scp){
    if(idType(tree.token)==8){ 
        // || , &&
        if(!strcmp(getExprType(*(tree.left),scp),getExprType(*(tree.mid1),scp)) && !strcmp(getExprType(*(tree.left),scp),"boolean")){
            return "boolean";
        }
        else{
        
            printError("expression not boolean");
            return NULL;
        }
    }
    if(idType(tree.token)==9){
        // >,>=,<,<=
        if(!strcmp(getExprType(*(tree.left),scp),getExprType(*(tree.mid1),scp)) && !strcmp(getExprType(*(tree.left),scp),"int")){
            return "boolean";
        }
        else{
            char* error=(char*)malloc(sizeof(char)*100);
            strcpy(error,"The operator '");
            strcat(error,tree.token);
            strcat(error,"' only compatible with int");
            printError(error);
            return NULL;
        }
    }
    if(idType(tree.token)==10){
        // !
        if(!strcmp(getExprType(*(tree.left),scp),"boolean")){
            return "boolean";
        }
        else{
            printError("operator '!' is only compatible with boolean");
            return NULL;
        }
    }
    if(idType(tree.token)==11){
        // /,+,*,-
        if(!strcmp(getExprType(*(tree.left),scp),getExprType(*(tree.mid1),scp)) && !strcmp(getExprType(*(tree.left),scp),"int")){
            return getExprType(*(tree.left),scp);
        }
        else{
            char* error=(char*)malloc(sizeof(char)*100);
            strcpy(error,"The operator '");
            strcat(error,tree.token);
            strcat(error,"' only compatible with int");
            printError(error);
            return NULL;
        }
    }
    if(idType(tree.token)==12){
        //&
        if(tree.mid2){
            if(!strcmp(tree.mid2->token,"SIZE")){
                if(strcmp(getExprType(*tree.mid2->left,scp),"int"))
                    printError("Index must be int");
            }
        }

        if(!strcmp(getExprType(*(tree.left),scp),"int")){
            return "intp";
        }
        else if(!strcmp(getExprType(*(tree.left),scp),"char")){
            return "charp";
        }
        else if(!strcmp(getExprType(*(tree.left),scp),"string")){
            return "charp";
        }
        else{
            printError("operator '&' is only compatible with int,string[i] or char");
            return NULL;
        }

    }
    if(idType(tree.token)==13){
        //FUNC_CALL
        checkFunctionCall(*tree.left->left,scp,getFuncParams(scp,tree.left->token));
        return getFuncType(scp,tree.left->token);
    }
    if(idType(tree.token)==14){
        //==,!=
         if(!strcmp(getExprType(*(tree.left),scp),getExprType(*(tree.mid1),scp)) && 
         (!strcmp(getExprType(*(tree.left),scp),"int") || 
         !strcmp(getExprType(*(tree.left),scp),"intp") || 
         !strcmp(getExprType(*(tree.left),scp),"char") || 
         !strcmp(getExprType(*(tree.left),scp),"charp") || 
         !strcmp(getExprType(*(tree.left),scp),"boolean") )){
            return "boolean";
        }
        else{
            char* error=(char*)malloc(sizeof(char)*100);
            strcpy(error,"The operator '");
            strcat(error,tree.token);
            strcat(error,"' only compatible with int,intp,char,charp or boolean");
            printError(error);
            return NULL;
        }
    }
    if(idType(tree.token)==15){
        // !
        if(!strcmp(getExprType(*(tree.left),scp),"int") || !strcmp(getExprType(*(tree.left),scp),"string")){
            return "int";
        }
        else{
            char* error=(char*)malloc(sizeof(char)*100);
            strcpy(error,"ABS only compatible with int or string");
            printError(error);
            return NULL;
        }
    }
       if(idType(tree.token)==16){
        //^
        if(!strcmp(getExprType(*(tree.left),scp),"intp")){
            return "int";
        }
        else if(!strcmp(getExprType(*(tree.left),scp),"charp")){
            return "char";
        }
        
        else{
            printError("operator '^' is only compatible with int or char");
            return NULL;
        }

    }
    if(idType(tree.token)==18){
    	return "char";
    
    }
    if(idType(tree.token)==19){
    	return "string";
    
    }
    //for x[i]
    if(tree.left)
        return "char";
    return getVarType(scp,tree.token);


}


int isNumber(char* string){
    if(!strcmp(string,"0"))
        return 1;
  	char * pEnd;
	long int li1;
  	li1 = strtol (string,&pEnd,10);
    if(li1)
        return 1;
    return 0;

}

char* getMyFuncReturn(scope scp){
    while(!scp.isFunction){
        scp = *scp.upperScope;
    }
    return scp.return_type;
}

void checkFunctionCall(node tree,scope scp,var* params){
    var* tmp = params;
    while(tmp){
		if(!tree.left){
			char* error=(char*)malloc(sizeof(char)*100);
			strcpy(error,"wrong number or types of arguments in function call (in the scope of '");
            strcat(error,scp.scope_id);
            strcat(error,"')");
            printError(error);
		}
        if(tree.mid1){
            if(!strcmp(tree.mid1->token,"STRING VAR")){
                if(strcmp("string",tmp->type)){
                	char* error=(char*)malloc(sizeof(char)*100);
					strcpy(error,"wrong number or types of arguments in function call (in the scope of '");
            		strcat(error,scp.scope_id);
            		strcat(error,"')");
            		printError(error);
                    
                }

            }
            else if(!strcmp(tree.mid1->token,"CHAR VAR")){
                if(strcmp("char",tmp->type)){
                	char* error=(char*)malloc(sizeof(char)*100);
					strcpy(error,"wrong number or types of arguments in function call (in the scope of '");
           			strcat(error,scp.scope_id);
           			strcat(error,"')");
            		printError(error);
                }

            }
            else if(!strcmp(tree.mid1->token,"FUNC CALL")){
                checkFunctionCall(*tree.mid1->left->left,scp,getFuncParams(scp,tree.mid1->left->token));
                if(strcmp(getFuncType(scp,tree.mid1->left->token),tmp->type)){
                    char* error=(char*)malloc(sizeof(char)*100);
					strcpy(error,"wrong number or types of arguments in call to '");
            		strcat(error,tree.mid1->left->token);
            		strcat(error,"'");
            		printError(error);
                }
                

            }
            else if(strcmp(getExprType(*tree.mid1,scp),tmp->type)){
            	char* error=(char*)malloc(sizeof(char)*100);
				strcpy(error,"wrong number or types of arguments in function call (in the scope of '");
           		strcat(error,scp.scope_id);
           		strcat(error,"')");
            	printError(error);
            }
        }
        else{
            if(!strcmp(tree.left->token,"STRING VAR")){
            	
                if(strcmp("string",tmp->type)){
                	char* error=(char*)malloc(sizeof(char)*100);
					strcpy(error,"wrong number or types of arguments in function call (in the scope of '");
           			strcat(error,scp.scope_id);
           			strcat(error,"')");
            		printError(error);
                }
            }
            else if(!strcmp(tree.left->token,"CHAR VAR")){
                if(strcmp("char",tmp->type)){
                	char* error=(char*)malloc(sizeof(char)*100);
					strcpy(error,"wrong number or types of arguments in function call (in the scope of '");
           			strcat(error,scp.scope_id);
           			strcat(error,"')");
            		printError(error);

                }
            }
            else if(!strcmp(tree.left->token,"FUNC CALL")){
                checkFunctionCall(*tree.left->left->left,scp,getFuncParams(scp,tree.left->left->token));
                if(strcmp(getFuncType(scp,tree.left->left->token),tmp->type)){
                	char* error=(char*)malloc(sizeof(char)*100);
					strcpy(error,"wrong number or types of arguments in call to '");
            		strcat(error,tree.left->left->token);
            		strcat(error,"'");
            		printError(error);
                }
                

            }
            else if(strcmp(getExprType(*tree.left,scp),tmp->type)){
            	char* error=(char*)malloc(sizeof(char)*100);
				strcpy(error,"wrong number or types of arguments in function call (in the scope of '");
           		strcat(error,scp.scope_id);
           		strcat(error,"')");
            	printError(error);
            }
            if(tmp->next){
                char* error=(char*)malloc(sizeof(char)*100);
				strcpy(error,"wrong number or types of arguments in function call (in the scope of '");
           		strcat(error,scp.scope_id);
           		strcat(error,"')");
            	printError(error);
            }
        }

        tmp=tmp->next;
        tree=*tree.left;
    }

    char* amit = (char*)malloc(sizeof(char)*100);
    
    
    if(!strcmp("VARIABLES",tree.token) && tree.left){        
    	char* error=(char*)malloc(sizeof(char)*100);
		strcpy(error,"wrong number or types of arguments in function call (in the scope of '");
        strcat(error,scp.scope_id);
        strcat(error,"')");
        printError(error);
    }
    
   
    
       
}

var* getFuncParams(scope scp,char* func){
    while(scp.innerScope != NULL){
        if(!strcmp(func,scp.innerScope->scope_id)){
            if(scp.innerScope->isFunction){
                return scp.innerScope->params;
            }
                
        }
        scp.innerScope = scp.innerScope->next;
    }
    if(scp.upperScope){
        return getFuncParams(*(scp.upperScope),func);
    }
    char* error=(char*)malloc(sizeof(char)*100);
    strcpy(error,"Function '");
    strcat(error,func);
    strcat(error,"' not declared");
    printError(error);
    return NULL;

}
