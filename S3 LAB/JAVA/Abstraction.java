import java.util.*;
abstract class Shape{
	abstract void numberOfSides();
}
class Triangle extends Shape{
	void numberOfSides(){
		System.out.println("Triangle : 3");
	}
}
class Rectangle extends Shape{
	void numberOfSides(){
		System.out.println("Rectangle : 4");
	}
}
class Hexagon extends Shape{
	void numberOfSides(){
		System.out.println("Hexagon : 6");
	}
}
class Abstraction{
	public static void main(String arr[]){
		Triangle t = new Triangle();
		t.numberOfSides();
		Rectangle r = new Rectangle();
		r.numberOfSides();
		Hexagon h = new Hexagon();
		h.numberOfSides();
	}
}
