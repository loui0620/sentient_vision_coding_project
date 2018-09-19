#include "ProjectWorkProgress.h"

namespace YourNameHere {

void ProjectWorkProgress::AddChild(std::shared_ptr<ProjectWorkAbstract> child)
{
   mChildrenLock.lock();
   mChildren.push_back(child);
   child->SetParent(this);
   mChildrenLock.unlock();
}

void ProjectWorkProgress::SetChildren(std::vector<std::shared_ptr<ProjectWorkAbstract>> children)
{
   mChildrenLock.lock();
   mChildren = children;
   mChildrenLock.unlock();
}

void ProjectWorkProgress::RemoveFirstChildWithColor(std::string color)
{
   mChildrenLock.lock();
   for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
   {
      auto child = *it;
      if (child->GetColor() == color)
      {
         child->SetParent(NULL);
         mChildren.erase(it);
         return;
      }
   }
   mChildrenLock.unlock();
}

void ProjectWorkProgress::RemoveAllChildrenWithColor(std::string color) {
   mChildrenLock.lock();

   for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
   {
      auto child = *it;
      if (child->GetColor() == color)
      {
         child->SetParent(NULL);
         mChildren.erase(it);
      }
   }
   mChildrenLock.unlock();
}


int64_t ProjectWorkProgress::GetDurationInDays() {
   return mEndDay - mStartDay;
}

void ProjectWorkProgress::SetDurationInDays(int64_t startDay, int64_t endDay)
{

}

float ProjectWorkProgress::GetProgress()
{
   return 1.0f;
}

void ProjectWorkProgress::SetProgress(float progress)
{

}

}