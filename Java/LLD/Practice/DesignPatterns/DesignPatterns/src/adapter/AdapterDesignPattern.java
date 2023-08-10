package adapter;

import adapter.adaptee.WeightMachineForBabies;
import adapter.adapter.WeightMachineAdapter;
import adapter.adapter.WeightMachineAdapterImpl;

public class AdapterDesignPattern {

    public static void main(String[] args) {
        WeightMachineAdapter weightMachineAdapter = new WeightMachineAdapterImpl(new WeightMachineForBabies());

        System.out.println(weightMachineAdapter.getWeightInKg());
    }
}
