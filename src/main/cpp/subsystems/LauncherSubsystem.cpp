#include "subsystems/LauncherSubsystem.h"

#include "Constants.h"

using namespace LauncherConstants;

LauncherSubsystem::LauncherSubsystem(void) : m_shooter{}, m_intake{} {
}

void LauncherSubsystem::Periodic() {
}

void LauncherSubsystem::shootAtSpeed(double speed) {
    
}

void LauncherSubsystem::intakeAndOutake(double speed1, double speed2) {
    if (speed1 - speed2 > kIntakeAndOutakeThreshold) {
        m_intake.runUntilSensor(speed1 - speed2);
        m_shooter.setSpeed(kDefaultShootingSpeed);
    } else if (speed1 - speed2 < -kIntakeAndOutakeThreshold) {
        m_intake.run(speed1 - speed2);
        m_shooter.setSpeed(kOutakeSpeed);
        // if (m_shooter.isAtSpeed()) {
        //     m_intake.run(speed1 - speed2);
        // }
    } else {
        m_shooter.setSpeed(kDefaultShootingSpeed);
        m_intake.run(0);
    }
}