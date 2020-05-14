class diamond{
    private int size;
    private char border;
    private char fill;
    public diamond(int inputSize){
        if(inputSize>39) inputSize=39;
        if(inputSize<1)  inputSize=1;
        this.size=inputSize;
        this.border='#';
        this.fill='*';
    }
    public diamond(int inputSize, char new_border){
        if(inputSize>39) inputSize=39;
        if(inputSize<1)  inputSize=1;
        this.size=inputSize;
        this.border=new_border;
        this.fill='*';
    }
    public diamond(int inputSize, char new_border, char new_fill){
        if(inputSize>39) inputSize=39;
        if(inputSize<1)  inputSize=1;
        this.size=inputSize;
        this.border=new_border;
        this.fill=new_fill;
    }
    void SetSize(int inputSize){
        if(inputSize < 1)
            size = 1;
        else if(inputSize > 39)
            size = 39;
        else
            size = inputSize;
    }
    void SetBorder(char new_border){
        if(new_border < 33 || new_border > 126)
            return ;
        else
            border = new_border;
    }
    void SetFill(char new_fill){
        if(new_fill < 33 || new_fill > 126)
            return ;
        else
            fill = new_fill;
    }
    int GetSize(){
        return size;
    }
    int Perimeter(){
        return 4*size;
    }
    double Area(){
        double ans = 0;
        ans = (Math.sqrt(3)/2) * Math.pow(size,2);
        return ans;
    }
    //Grow and Shrink return 1 if success
    int Grow(){
        if(size >= 39)
            return 0;
        else{
            ++size;
            return 1;
        }
    }
    int Shrink(){
        if(size <= 1)
            return 0;
        else{
            --size;
            return 1;
        }
    };
    void Draw()
    {
        if(size==1) System.out.printf("%c\n",border);
        else
        {
            
            for(int i=1;i<=size;i++)
            {
                
                for(int j=1;j<=(size-i);j++)System.out.printf(" ");
                System.out.printf("%c ",border);
                if(i==1)System.out.printf("\n");
                for(int j=1;j<=(i-2);j++) System.out.printf("%c ",fill);
                if(i!=1)System.out.printf("%c\n",border);
            
            }
            for(int i=(size-1);i>=1;i--)
            {
                for(int j=1;j<=(size-i);j++)System.out.printf(" ");
                System.out.printf("%c ",border);
                if(i==1)System.out.printf("\n");
                for(int j=1;j<=(i-2);j++) System.out.printf("%c ",fill);
                if(i!=1)System.out.printf("%c\n",border);
            }
            
        }
    }
    void Summary()
    {
        System.out.printf("Size of diamond's side = %d units.\n",size);
        System.out.printf("Perimeter of diamond = %d units.\n",Perimeter());
        System.out.printf("Area of diamond = %.2f units.\n",Area());
        System.out.printf("Diamond looks like:\n");
        Draw();
    }   

};
public class hw3{
    public static void main(String[] args)
    {
        diamond d1 = new diamond (-5); diamond d2 = new diamond (7,'^'); diamond d3 = new diamond (12,'X','O'); diamond d4 = new diamond (50,'$','o');
        System.out.println("d1 has size = " + d1.GetSize() + " utils"); d1.Draw();
        System.out.println("d2 has size = " + d2.GetSize() + " utils"); d2.Draw();
        System.out.println("d3 has size = " + d3.GetSize() + " utils"); d3.Draw();
        System.out.println("d4 has size = " + d4.GetSize() + " utils"); d4.Draw();
        d1.Shrink(); d2.Shrink();
        d3.Grow(); d4.Grow();
        System.out.println("d1 now has size = " + d1.GetSize() + " utils"); System.out.println("d2 now has size = " + d2.GetSize() + " utils"); System.out.println("d3 now has size = " + d3.GetSize() + " utils"); System.out.println("d4 now has size = " + d4.GetSize() + " utils");
        System.out.println("d2 has perimeter = " + d2.Perimeter() + " utils"); System.out.println("d3 has perimeter = " + d3.Perimeter() + " utils"); System.out.println("d2 has area = " + d2.Area() + " utils"); System.out.println("d3 has area = " + d3.Area() + " utils");
        d1.Draw();
        d1.Grow();
        System.out.println("... and grows:"); d1.Draw();
        System.out.println();
        d1=d2;
        System.out.println("d1 now has size = " + d1.GetSize() + " utils"); d1.Draw();
        d2.SetBorder('@');
        d2.SetFill('-');
        System.out.println("d2 now looks like:"); d2.Draw();
        System.out.println();
        d2.SetBorder('\n');
        d2.SetFill('\n');
        System.out.println("d2 now looks like:"); d2.Draw();
        System.out.println();
        System.out.println("Here is a summary on d3:"); d3.Summary();
    }
}