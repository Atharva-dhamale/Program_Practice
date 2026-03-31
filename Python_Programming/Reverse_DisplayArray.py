

def ReverseDisplayArray(Arr):

    print("Reversed Array :",end=" ")
    for i in range(len(Arr)-1,-1,-1):
        print(Arr[i],"",end=" ")

    print()

def main():

    No=(int(input("Enter numbers of elements : ")))

    Arr=[]

    print("Enter the elements : ")

    for i in range(1,No+1):
        value=int(input())
        Arr.append(value)

    print("Original Array : ",Arr)
    ReverseDisplayArray(Arr)


if __name__=="__main__":
    main()