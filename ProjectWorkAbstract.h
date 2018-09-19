#pragma once

// Please do not modify this header

#include <memory>
#include <vector>
#include <string>
#include <cstdint>
#include <mutex>

namespace Sentient {

   class ProjectWorkAbstract
   {
   public:
      virtual void AddChild(std::shared_ptr<ProjectWorkAbstract> child) = 0;
      virtual void SetChildren(std::vector<std::shared_ptr<ProjectWorkAbstract>> children) = 0;
      virtual void RemoveFirstChildWithColor(std::string color) = 0;
      virtual void RemoveAllChildrenWithColor(std::string color) = 0;

      virtual void                  SetParent(ProjectWorkAbstract* parent) = 0;
      virtual ProjectWorkAbstract*  GetParent() = 0;

      virtual void         SetColor(std::string color) = 0;
      virtual std::string  GetColor() = 0;

      virtual int64_t GetDurationInDays() = 0;
      virtual void    SetDurationInDays(int64_t startDay, int64_t endDay) {};

      virtual float  GetProgress() { return 0.0f; }
      virtual void   SetProgress(float progress) {}

   protected:

   };

}