package decorator;

public class DecoratorDesignPattern {

    public static void main(String[] args) {

        // If we want Margerita + ExtraCheese
        BasePizza pizza1 = new ExtraCheese(new Margerita()) ;

        System.out.println(pizza1.cost());

        // If we want Margerita + ExtraCheese + Mashroom

        BasePizza pizza2 =  new Mushroom(new ExtraCheese(new Margerita())) ;

        System.out.println(pizza2.cost());

    }
}
