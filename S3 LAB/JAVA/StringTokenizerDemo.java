import java.util.StringTokenizer;

public class StringTokenizerDemo  {
    public static void main(String[] args) {
       
        System.out.println("Enter a line of integers separated by spaces:");
        String inputLine = System.console().readLine();

        
        StringTokenizer tokenizer = new StringTokenizer(inputLine);

        
        int sum = 0;
        System.out.println("Individual integers:");
        while (tokenizer.hasMoreTokens()) {
            String token = tokenizer.nextToken();
            int number = Integer.parseInt(token);
            System.out.println(number);
            sum += number;
        }

        
        System.out.println("Sum of all integers: " + sum);
    }
}
