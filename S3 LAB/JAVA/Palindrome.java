import java.util.*;
 class Palindrome{
 	public static void main(String arr[]){
 	String str;
 	int flag = 0;
 	Scanner sc = new Scanner(System.in);
 	System.out.println("Enter a string: ");
 	str = sc.nextLine();
 	int len = str.length();
 	str = str.toLowerCase();
 	
 	int strLen = len-1;
 	
 	for(int i=0;i<len;i++){
 		if(str.charAt(i)!=str.charAt(strLen)){
 			flag = 1;
 			break;
 		}
 		strLen--;
 	}
 	
 	if(flag == 1){
 		System.out.println("Not palindrome..!!");
 	}
 	else{
 		System.out.println("Is a palindrome..!!");
 	}
 	
 	
 	}
 }
