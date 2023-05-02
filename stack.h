#if !defined(STACK_IR)
#define STACK_IR

//Libraries
 #include<stdlib.h>
 #include<vector>
 #include<stdio.h>
 #include<string>

 using namespace std;
//////////////////
//Representing each value:
struct Object{
    string value;
    bool used;
};

//Macros::---------------------------------
#define ObjectStream vector<Object>
//-----------------------------------------

struct Memory{
    ObjectStream memory;
};
//All memory
Memory R1;
Memory R2;
Memory R3;
Memory R4;
Memory R5;
Memory R6;
Memory R7;
Memory R8;
Memory R9;
Memory R10; 
Memory R11; 
Memory R12; 



//Value pushers
void PUSH_R1(string value);
void PUSH_R2(string value);
void PUSH_R3(string value);
void PUSH_R4(string value);
void PUSH_R5(string value);
void PUSH_R6(string value);
void PUSH_R7(string value);
void PUSH_R8(string value);
void PUSH_R9(string value);
void PUSH_R10(string value);
void PUSH_R11(string value);
void PUSH_R12(string value);
string CHECK_LIGHTEST_STACK();



//Variable stack
struct Variable{
 string name;
 int address;
};
//Stack for variables
vector<Variable> variableStack;



//Variable pushers:
void PUSH_VAR(string name, string value){
    Variable var;
    var.name = name;
    PUSH_R1(value);
    var.address = R1.memory.size()-1;    
    variableStack.push_back(var);
}
//Definations for value pushers:
void PUSH_R1(string value){
    Object obj;
    obj.value = value;
    obj.used = 1;
    R1.memory.push_back(obj);
}
void PUSH_R2(string value){
    Object obj;
    obj.value = value;
    obj.used = 1;
    R2.memory.push_back(obj);
}
void PUSH_R3(string value){
    Object obj;
    obj.value = value;
    obj.used = 1;
    R3.memory.push_back(obj);
}
void PUSH_R4(string value){
    Object obj;
    obj.value = value;
    obj.used = 1;
    R4.memory.push_back(obj);
}
void PUSH_R5(string value){
    Object obj;
    obj.value = value;
    obj.used = 1;
    R5.memory.push_back(obj);
}
void PUSH_R6(string value){
    Object obj;
    obj.value = value;
    obj.used = 1;
    R6.memory.push_back(obj);
}
void PUSH_R7(string value){
    Object obj;
    obj.value = value;
    obj.used = 1;
    R7.memory.push_back(obj);
}
void PUSH_R8(string value){
    Object obj;
    obj.value = value;
    obj.used = 1;
    R8.memory.push_back(obj);
}
void PUSH_R9(string value){
    Object obj;
    obj.value = value;
    obj.used = 1;
    R9.memory.push_back(obj);
}
void PUSH_R10(string value){
    Object obj;
    obj.value = value;
    obj.used = 1;
    R10.memory.push_back(obj);
}
void PUSH_R11(string value){
    Object obj;
    obj.value = value;
    obj.used = 1;
    R11.memory.push_back(obj);
}
void PUSH_R12(string value){
    Object obj;
    obj.value = value;
    obj.used = 1;
    R12.memory.push_back(obj);
}


//Function to read the variable's value in the memory
string GET_VAR(string name){
    for(Variable var : variableStack){
        if(var.name == name){
            return R1.memory[var.address].value;
        }
    }
    return "\\NOTFOUND";
}

//Assign the new value to the variable
void ASSIGN_VAR(string name, string value){
    for(Variable& var : variableStack){
        if(var.name == name){
            R1.memory[var.address].used = 0;
            PUSH_R1(value);
            var.address = R1.memory.size()-1;
            R1.memory[var.address].used = 1; // mark the new object as used
        }
    }
}

void removeElementAtIndex(ObjectStream& vec, int index) {
    if (index < vec.size()) {
        vec.erase(vec.begin() + index);
    }
}


void GC(){
    //For R1:
    int i = 0;
    for(Object obj : R1.memory){
        if(obj.used == 0){
            removeElementAtIndex(R1.memory,i);
        }
        i++;
    }

    //For R2
    i = 0;
    for(Object obj : R2.memory){
        if(obj.used == 0){
            removeElementAtIndex(R2.memory,i);
        }
        i++;
    }
    //For R3
    i = 0;
    for(Object obj : R3.memory){
        if(obj.used == 0){
            removeElementAtIndex(R3.memory,i);
        }
        i++;
    }
    //For R4
    i = 0;
    for(Object obj : R4.memory){
        if(obj.used == 0){
            removeElementAtIndex(R4.memory,i);
        }
        i++;
    }
    //For R5
    i = 0;
    for(Object obj : R5.memory){
        if(obj.used == 0){
            removeElementAtIndex(R5.memory,i);
        }
        i++;
    }
    //For R6
    i = 0;
    for(Object obj : R6.memory){
        if(obj.used == 0){
            removeElementAtIndex(R6.memory,i);
        }
        i++;
    }
    //For R7
    i = 0;
    for(Object obj : R7.memory){
        if(obj.used == 0){
            removeElementAtIndex(R7.memory,i);
        }
        i++;
    }
    //For R8
    i = 0;
    for(Object obj : R8.memory){
        if(obj.used == 0){
            removeElementAtIndex(R8.memory,i);
        }
        i++;
    }
    //For R9
    i = 0;
    for(Object obj : R9.memory){
        if(obj.used == 0){
            removeElementAtIndex(R9.memory,i);
        }
        i++;
    }
    //For R10
    i = 0;
    for(Object obj : R10.memory){
        if(obj.used == 0){
            removeElementAtIndex(R10.memory,i);
        }
        i++;
    }
    //For R11
    i = 0;
    for(Object obj : R11.memory){
        if(obj.used == 0){
            removeElementAtIndex(R11.memory,i);
        }
        i++;
    }
    //For R12
    i = 0;
    for(Object obj : R12.memory){
        if(obj.used == 0){
            removeElementAtIndex(R12.memory,i);
        }
        i++;
    }

}

#endif // STACK_IR
