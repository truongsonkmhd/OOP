package stactic_singleton_pattern.observer;

public class_oop WeatherStation {
    public static void main(String[] args) {
        // Tạo đối tượng WeatherData (Subject)
        WeatherData weatherData = new WeatherData();

        // Tạo đối tượng CurrentConditionsDisplay (Observer) và đăng ký với WeatherData
        CurrentConditionsDisplay currentDisplay = new CurrentConditionsDisplay(weatherData);

        // Giả lập thay đổi thời tiết
        weatherData.setMeasurements(80, 65, 30.4f);
        weatherData.setMeasurements(82, 70, 29.2f);
        weatherData.setMeasurements(78, 90, 29.2f);
    }
}