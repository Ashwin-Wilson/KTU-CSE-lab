import java.util.*;
class BinarySearch{
	public static void main(String arg[]){
		Scanner sc = new Scanner(System.in);
		int i,j,limit,beg,mid,end,item,temp;
		
		System.out.println("Enter size of the array: ");
		limit = sc.nextInt();
		int arr[] = new int[limit];
		System.out.println("Enter "+limit+" numbers : \n");
		for(i=0;i<limit;i++){
			arr[i] = sc.nextInt();
		}
		
		for(j=limit-1;j>=0;j--){
			for(i=0;i<j;i++ ){
				if(arr[i]>arr[i+1]){
					temp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = temp;
				}
			}
		}
		System.out.println("Sorted array: \n");
		for(i=0;i<limit;i++){
			System.out.println("\t"+arr[i]);
		}
		System.out.println("Enter item to search");
		item = sc.nextInt();
		beg = 0;
		end = limit-1;
		mid = (beg+end)/2;
		while((arr[mid] != item) && (beg<=end)){
			if(item < arr[mid]){
				end = mid-1;
				mid = (beg+end)/2;
			}
			else{
				beg = mid+1;
				mid = (beg+end)/2;
			}
		}
		if(arr[mid] == item){
			System.out.println("Element found at : "+ (mid+1));
		}
		else{
			System.out.println("Element not found\n");
		}
		
	}
}
