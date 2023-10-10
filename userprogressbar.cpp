#include "userprogressbar.h"

UserProgressBar::UserProgressBar(int requiredValue, QProgressBar *parent) : QProgressBar{parent} {
  requiredValue_ = requiredValue;
  setRange(0, 100);
  setStyleSheet(normalStyle);
}

void UserProgressBar::SetRequiredValue(int requiredValue) {
  requiredValue_ = requiredValue;

  emit RequiredValueChanged(requiredValue_);
}

void UserProgressBar::UpdateColor() {
  if (value() < requiredValue_)
      setStyleSheet(dangerStyle);
  else
      setStyleSheet(normalStyle);
}
