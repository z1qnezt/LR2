#include <gtest/gtest.h>
#include "Program.cpp"
#include "ConceptualExample.cpp"
#include "DynamicShapes.cpp"
#include "StaticShapes.cpp"

using namespace std;

TEST(ConceptualExampleTest, ConceptualExampleDecoratorOperationTest) {
    ConcreteComponent component;
    ConcreteDecoratorA decoratorA(std::make_shared<ConcreteComponent>());
    EXPECT_EQ(decoratorA.operation(), "ConcreteDecoratorA ( CONCRETE COMPONENT )");
}

TEST(ConceptualExampleTest, ConceptualExampleNestedDecoratorOperationTest) {
    ConcreteComponent component;
    ConcreteDecoratorB decoratorB(std::make_shared<ConcreteDecoratorA>(std::make_shared<ConcreteComponent>()));
    EXPECT_EQ(decoratorB.operation(), "ConcreteDecoratorB [ ConcreteDecoratorA ( CONCRETE COMPONENT ) ]");
}

TEST(ConceptualExampleTest, ConceptualExampleConditionalDecoratorTest) {
    ConcreteComponent component;
    std::shared_ptr<Component> decorator;
    if (true) {
        decorator = std::make_shared<ConcreteDecoratorB>(std::make_shared<ConcreteDecoratorA>(std::make_shared<ConcreteComponent>()));
    } else {
        decorator = std::make_shared<ConcreteDecoratorA>(std::make_shared<ConcreteDecoratorB>(std::make_shared<ConcreteComponent>()));
    }
    EXPECT_EQ(decorator->operation(), "ConcreteDecoratorB [ ConcreteDecoratorA ( CONCRETE COMPONENT ) ]");
}
