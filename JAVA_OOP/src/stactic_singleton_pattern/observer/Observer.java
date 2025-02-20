package stactic_singleton_pattern.observer;

// Giao diện Observer
public interface Observer {
    void update(float temperature, float humidity, float pressure);
}