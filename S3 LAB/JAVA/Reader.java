import java.io.*;
public class Reader {
	 public static void main(String[] args) throws IOException {
	 
	      
	        FileWriter writer = new FileWriter("input.txt");
	        BufferedWriter bufferedWriter = new BufferedWriter(writer);

	        bufferedWriter.write("My name is Ashwin wilson");
	        bufferedWriter.close();
	        writer.close();
	        
	      
	        FileReader reader = new FileReader("input.txt");
	        BufferedReader bufferedReader = new BufferedReader(reader);

	        String line;
	        while ((line = bufferedReader.readLine()) != null) {
	            System.out.println(line);
	        }
	        bufferedReader.close();
	        reader.close();

	    }
}
