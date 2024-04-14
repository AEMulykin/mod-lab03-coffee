// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"
class AutomataTest : public ::testing::Test {
protected:
Automata machine;
    void SetUp() override {}
};
TEST_F(AutomataTest, ThrowsError_WhenOperationIsIncorrect) {
    machine.SetState(CHECK);
    EXPECT_THROW(machine.PowerOn(), std::domain_error);
    EXPECT_THROW(machine.PowerOff(), std::domain_error);
    machine.SetState(OFF);
    EXPECT_THROW(machine.InsertCoin(100), std::domain_error);
    EXPECT_THROW(machine.MakeDrink(), std::domain_error);
    machine.SetState(WAIT);
    EXPECT_THROW(machine.CancelTransaction(), std::domain_error);
    EXPECT_THROW(machine.SelectOption(3), std::domain_error);
    machine.SetState(ACCEPT);
    EXPECT_THROW(machine.IsPaymentSufficient(), std::domain_error);
    EXPECT_THROW(machine.CompleteTransaction(), std::domain_error);  
    machine.SetState(ACCEPT);
    EXPECT_THROW(machine.InsertCoin(-500), std::invalid_argument);
}
TEST_F(AutomataTest, StateChangesCorrectly_AfterOperations) {
    // Test state transitions
    machine.PowerOn();
    EXPECT_EQ(WAIT, machine.GetState());    
    machine.InsertCoin(1000);
    EXPECT_EQ(ACCEPT, machine.GetState());    
    machine.SelectOption(5);  // assuming option 5 is valid
    EXPECT_EQ(CHECK, machine.GetState());    
    machine.MakeDrink();
    EXPECT_EQ(COOK, machine.GetState());    
    machine.CompleteTransaction();
    EXPECT_EQ(WAIT, machine.GetState());
    machine.InsertCoin(10);
    machine.SelectOption(5);
    machine.CancelTransaction();
    EXPECT_EQ(WAIT, machine.GetState());
    machine.PowerOff();
    EXPECT_EQ(OFF, machine.GetState());
}
