#pragma once

#include "ProjectWorkAbstract.h"

namespace YourNameHere {

class ProjectWork : public Sentient::ProjectWorkAbstract
{
public:

   // Please do not modify these function signatures.

   virtual void AddChild(std::shared_ptr<ProjectWorkAbstract> child) override;
   virtual void SetChildren(std::vector<std::shared_ptr<ProjectWorkAbstract>> children) override;
   virtual void RemoveFirstChildWithColor(std::string color) override;
   virtual void RemoveAllChildrenWithColor(std::string color) override;

   virtual void SetParent(ProjectWorkAbstract* parent) override { mParent = parent; };
   virtual ProjectWorkAbstract* GetParent() override { return mParent; }

   virtual void SetColor(std::string color) override { mColor = color; };
   virtual std::string GetColor() override { return mColor; }

   virtual int64_t GetDurationInDays() override;

   // Assume getters/setters for other properties also exist.

protected:

   std::mutex mChildrenLock;
   std::vector<std::shared_ptr<ProjectWorkAbstract>> mChildren;
   ProjectWorkAbstract* mParent;
   std::string mColor;
   std::string mTitle;
   int64_t mStartDay;
   int64_t mEndDay;

};

}