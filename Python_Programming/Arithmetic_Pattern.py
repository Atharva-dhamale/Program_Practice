

def Arithmetic_Pattern(Rows,Cols):

    if(Rows!=Cols):
        print("Invalid number of rows or columns")
        return

    for i in range(1,Rows+1):
        for j in range(1,Cols+1):

            if((i==(Cols//2)+1) or ((j==(Rows//2)+1))):
                print("*",end="")
            else:
                print(" ",end="")

        print("")

    print("")
    
    for i in range(1,Rows+1):
        for j in range(1,Cols+1):
            if(i==(Rows//2)):
                print("*",end="")
            else:
                print(" ",end="")
        print("")

    
            
    for i in range(1,Rows+1):
        for j in range(1,Cols+1):
            if(i==j or j==Rows-i+1):
                print("*",end="")
            else:
                print(" ",end="")
        print("")

    print("")
    print("")

    for i in range(1,Rows+1):
        for j in range(1,Cols+1):
            if(i+j==Rows+1):
                print("*",end="")
            else:
                print(" ",end="")

        print("")


def main():
    Rows=0
    Cols=0

    Rows=int(input("Enter number of Rows : "))
    Cols=int(input("Enter number of Columns : "))

    Arithmetic_Pattern(Rows,Cols)

if __name__=="__main__":
    main()
    
