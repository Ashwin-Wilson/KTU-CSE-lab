class First extends Thread{
    void display(String msg){
        System.out.println("["+msg);
        try{
            sleep(1000);
        }catch(InterruptedException e){
             System.out.println(e);
        }
         System.out.println("]");
    }
}
class Second extends Thread{
    First ob;
    String str1;
    Second(First obj, String str){
        ob = obj;
        str1 = str;
        start();
    }
    public void run(){
        synchronized(ob){
            ob.display(str1);
        }
    }
}
class SynchronisationDemo{
    public static void main(String arg[]){
        First F =  new First();
        Second s1 = new Second(F, "Ashwin");
        Second s2 = new Second(F, "Aarav");
        Second s3 = new Second(F, "Anadhu");
        
    }
}