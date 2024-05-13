#include <iostream>
#include <memory>
#include <string>

// Component Interface
class TextFilter {
public:
    virtual ~TextFilter() {}
    virtual std::string apply(const std::string& text) const = 0;
};

// Concrete Component
class PlainText : public TextFilter {
public:
    std::string apply(const std::string& text) const override {
        return text;
    }
};

// Decorator
class TextDecorator : public TextFilter {
protected:
    std::shared_ptr<TextFilter> component;

public:
    TextDecorator(std::shared_ptr<TextFilter> comp) : component(comp) {}

    std::string apply(const std::string& text) const override {
        return component->apply(text);
    }
};

// Concrete Decorator: Uppercase
class UppercaseDecorator : public TextDecorator {
public:
    UppercaseDecorator(std::shared_ptr<TextFilter> comp) : TextDecorator(comp) {}

    std::string apply(const std::string& text) const override {
        std::string result = TextDecorator::apply(text);
        for (char& c : result) {
            c = std::toupper(c);
        }
        return result;
    }
};

// Concrete Decorator: Bold
class BoldDecorator : public TextDecorator {
public:
    BoldDecorator(std::shared_ptr<TextFilter> comp) : TextDecorator(comp) {}

    std::string apply(const std::string& text) const override {
        return "<b>" + TextDecorator::apply(text) + "</b>";
    }
};

int main() {
    std::shared_ptr<TextFilter> plainText = std::make_shared<PlainText>();
    std::cout << "Original text: " << plainText->apply("Hello, world!") << std::endl;

    std::shared_ptr<TextFilter> uppercaseText = std::make_shared<UppercaseDecorator>(plainText);
    std::cout << "Uppercase text: " << uppercaseText->apply("Hello, world!") << std::endl;

    std::shared_ptr<TextFilter> boldUppercaseText = std::make_shared<BoldDecorator>(uppercaseText);
    std::cout << "Bold uppercase text: " << boldUppercaseText->apply("Hello, world!") << std::endl;

    return 0;
}
