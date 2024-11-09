class ThrowsClass{
	void throwException()throws ArithmeticException{
			int result = 10/0;
	}
}

class Exception{
	public static void main(String arr[]){
		try{
			ThrowsClass t = new ThrowsClass();
			t.throwException();
		}
		catch(ArithmeticException e ){
			System.out.println(e);
		}
		finally{
			System.out.println("All the Exceptions are handled");
		}
	}
}


