import java.io.*;
public class ReadAndWrite {
	public static void main(String[] args) {
      	String inputFileName = "input.txt";
        try {
        	
         	FileReader reader = new FileReader(inputFileName);
	        BufferedReader bufferedReader = new BufferedReader(reader);
	     	FileWriter writer = new FileWriter("output.txt");
	        BufferedWriter bufferedWriter = new BufferedWriter(writer);

	        String line;
	        while ((line = bufferedReader.readLine()) != null) {
	        	bufferedWriter.write(line);
	        }

	        bufferedReader.close();
	        reader.close();

	        bufferedWriter.close();
	        writer.close();
	        
            
	        
        } catch (FileNotFoundException e) {
            System.err.println("Error: File " + inputFileName + " not found.");
        } catch (IOException e) {
            System.err.println("Error: IOException occurred while reading or writing file.");
            e.printStackTrace();
        }
    }
}
