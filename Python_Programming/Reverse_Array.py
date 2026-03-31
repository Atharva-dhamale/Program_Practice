

def ReverseArray(Arr):

    start=0
    end=0
    temp=0

    end=(len(Arr))-1

    while(start<end):
        temp=Arr[start]
        Arr[start]=Arr[end]
        Arr[end]=temp

        start=start+1
        end=end-1

    return Arr


def main():

    No=(int(input("Enter numbers of elements : ")))

    Arr=[]

    print("Enter the elements : ")

    for i in range(1,No+1):
        value=int(input())
        Arr.append(value)

    print("Original Array : ",Arr)
    print("Reversed Array : ",ReverseArray(Arr))


if __name__=="__main__":
    main()