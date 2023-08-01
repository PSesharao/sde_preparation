package decorator;

import decorator.BasePizza;

public class VegDelight extends BasePizza {

    @Override
    public int cost() {
        return 120;
    }
}