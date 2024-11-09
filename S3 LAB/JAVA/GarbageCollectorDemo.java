public class GarbageCollectorDemo {

    public static void main(String[] args) {

        MyClass obj1 = new MyClass("Object 1");
        MyClass obj2 = new MyClass("Object 2");

        obj1 = null;
        obj2 = null;

        System.gc();

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class MyClass {
    private String name;

    public MyClass(String name) {
        this.name = name;
        System.out.println(name + " created.");
    }

    protected void finalize() {
        System.out.println(name + " is being garbage collected.");
    }
}
