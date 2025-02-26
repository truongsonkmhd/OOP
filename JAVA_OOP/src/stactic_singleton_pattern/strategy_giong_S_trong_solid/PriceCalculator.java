package stactic_singleton_pattern.strategy_giong_S_trong_solid;

import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;

public class PriceCalculator {
    private static final Map<String, Function<Integer, Float>> getPriceStrategies = new HashMap<>();

    static {
        getPriceStrategies.put("preOrder", PriceCalculator::preOrderPrice);
        getPriceStrategies.put("promotion", PriceCalculator::promotionPrice);
        getPriceStrategies.put("blackFriday", PriceCalculator::blackFridayPrice);
        getPriceStrategies.put("dayPrice", PriceCalculator::dayPrice);
        getPriceStrategies.put("default", PriceCalculator::defaultPrice);
    }

    public static float getPrice(int originalPrice, String typePromotion) {
        return getPriceStrategies.getOrDefault(typePromotion, PriceCalculator::defaultPrice)
                .apply(originalPrice);
    }

    private static float preOrderPrice(int originalPrice) {
        return originalPrice * 0.9f; // Giảm 10%
    }

    private static float promotionPrice(int originalPrice) {
        return originalPrice * 0.8f; // Giảm 20%
    }

    private static float blackFridayPrice(int originalPrice) {
        return originalPrice * 0.7f; // Giảm 30%
    }

    private static float dayPrice(int originalPrice) {
        return originalPrice * 0.95f; // Giảm 5%
    }

    private static float defaultPrice(int originalPrice) {
        return (float) originalPrice; // Không giảm giá
    }

    public static void main(String[] args) {
        System.out.println(getPrice(1000, "preOrder"));     // 900.0
        System.out.println(getPrice(1000, "promotion"));    // 800.0
        System.out.println(getPrice(1000, "blackFriday"));  // 700.0
        System.out.println(getPrice(1000, "dayPrice"));     // 950.0
        System.out.println(getPrice(1000, "unknownType"));  // 1000.0 (Default)
    }

    // cách  thông thường : => vi phạm nguyên lý P trong SOLID

    private float getPrice2(int originalPrice , String typePromotion){
        if(typePromotion == "preOrder"){
            return (float) (originalPrice* 0.8);
        }

        if(typePromotion == "preOrder"){
            return (float) (originalPrice* 0.8);
        }

        if(typePromotion == "preOrder"){
            return (float) (originalPrice* 0.8);
        }

        throw new IllegalArgumentException("No valid promotion type");
    }
}
