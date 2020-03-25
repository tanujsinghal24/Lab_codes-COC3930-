import java.util.*;
class kth{
    public static int index_num(int[] a,int[] b,int ai,int bi,int ae,int be,int k){
        if(ai==ae){
            System.out.print("\nArray A => ");
            print_arr(a,ai,ae);
            System.out.print("\nArray B => ");
            print_arr(b,bi,be);
            return b[bi+k];
        }
        if(bi==be){
            System.out.print("\nArray A => ");
            print_arr(a,ai,ae);
            System.out.print("\nArray B => ");
            print_arr(b,bi,be);
            return a[ai+k];
        }
        int mida = (ae - ai)/2; 
        int midb = (be - bi)/2; 

        System.out.print("\nArray A => ");
        print_arr(a,ai,ae);
        System.out.print("\nArray B => ");
        print_arr(b,bi,be);
        System.out.println();

        System.out.println("ai="+ai+"  ae="+ae);
        System.out.println("bi="+bi+"  be="+be);
        System.out.println("mida index: " +mida +"  midb index:" + midb + "  k:" + k);

        if (mida + midb < k) 
        { 
            if (a[ai+mida] > b[bi+midb]) 
                return index_num(a, b , ai, bi+ midb + 1, ae, be, k - midb - 1); 
            else
                return index_num(a, b , ai+ mida + 1, bi, ae, be,k - mida - 1);
        } 
        else
        { 
            if (a[ai+mida] > b[bi+midb]) 
                return index_num(a, b, ai, bi, ai+mida, be, k); 
            else
                return index_num(a, b, ai, bi, ae, bi+ midb, k); 
        } 
    }

    public static void print_arr(int[] x,int s,int e){
        for(int j=s;j<e;j++){
            System.out.print(x[j]+" ");
        }
    }

    public static void main(String args[]){
        // int[] a = {2, 4, 6, 7, 9}; 
        // int[] b = {1, 4, 8, 10};
        // int k=6;
        // int n=a.length;
        // int m=b.length;
        int[] a = new int[100];
        int[] b = new int[100]; 
        int nl,ml;
        Hashtable<Integer, Integer> 
        hm = new Hashtable<Integer, Integer>(); 
        System.out.println();
        Scanner sc=new Scanner(System.in);
        
        System.out.println("Enter number of elements for first array:");
        int n=sc.nextInt();
        nl=n;
        System.out.println("Enter number of elements for second array:");
        int m=sc.nextInt(); 
        ml=m;
        System.out.println();
        
        System.out.println("Enter sorted elements for first array:");
        for(int i=0;i<n;i++){
            int temp=sc.nextInt();
            if(i==0){
                a[i]=temp;
                hm.put(a[i],1);
            }
            else if(i>0 && !hm.containsKey(temp) && temp>a[i-1]){
                a[i]=temp;
                hm.put(a[i],1);
            }
            else{
                nl-=1;
                n-=1;
                i-=1;
            }  
        }
        for(int i=0;i<n;i++){
            System.out.print(a[i]+" ");
        }
        System.out.println();
        System.out.println("Enter sorted elements for second array:");
        for(int i=0;i<m;i++){
            int temp=sc.nextInt();
            if(hm.containsKey(temp)){
                ml-=1;
                m-=1;
                i-=1;
            }
            else{
                if(i==0){
                    b[i]=temp;
                    hm.put(b[i],1);
                }
                else if(i>0 &&temp>b[i-1]){
                    b[i]=temp;
                    hm.put(b[i],1);
                }
                else{
                    ml-=1;
                    m-=1;
                    i-=1;
                }  
            }

        }
        for(int i=0;i<m;i++){
            System.out.print(b[i]+" ");
        }
        System.out.println();
        System.out.println();
        System.out.println("Enter k ,number of element to be found:");
        int k = sc.nextInt();
        // for(int i=1;i<=nl+ml;i++)
        System.out.println("\n\n"+k+"th smalest element in union is => "+index_num(a, b, 0, 0, nl, ml, k - 1) + "\n\n");
    }
}