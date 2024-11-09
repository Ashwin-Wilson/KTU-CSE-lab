import java.util.*;

class Quicksort{
	static void quickSort(String names[],int low,int high){
		if(low<high){
			int l=low,h=high,p=low;
			String temp;
			while(l<h){
				while( (names[l].compareTo(names[p]) <=0)&& l<h){
					l++;
				}
				while(names[h].compareTo(names[p]) > 0){
					h--;
				}
				if(l<h){
					temp = names[l];
					names[l] = names[h];
					names[h] = temp;  
				}
				temp = names[h];
				names[h] = names[p];
				names[p] = temp;
				
				quickSort(names,0,h-1);
				quickSort(names,h+1,high);
			}
		}
	
	}

	public static void main(String arr[]){
		
 		Scanner sc = new Scanner(System.in);
		System.out.println("How many names do you have: ");
		int n = sc.nextInt();
		String names[] = new String[n];
		
		sc.nextLine();
		for(int i=0;i<n;i++){
			
			System.out.println("Enter name "+(i+1)+": ");
			names[i] = sc.nextLine();
		}
		
		quickSort(names,0,n-1);
		
		System.out.println("Sorted list:");
		for(String i : names){
			System.out.println(i);
		}
	}
}
