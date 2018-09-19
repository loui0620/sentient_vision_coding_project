#include "ProjectWork.h"

namespace YourNameHere {

void ProjectWork::AddChild(std::shared_ptr<ProjectWorkAbstract> child)
{
   mChildrenLock.lock();
   mChildren.push_back(child);
   child->SetParent(this);
   mChildrenLock.unlock();
}

void ProjectWork::SetChildren(std::vector<std::shared_ptr<ProjectWorkAbstract>> children)
{
   mChildrenLock.lock();
   mChildren = children;
   mChildrenLock.unlock();
}

void ProjectWork::RemoveFirstChildWithColor(std::string color)
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

void ProjectWork::RemoveAllChildrenWithColor(std::string color) {
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

int64_t ProjectWork::GetDurationInDays() {
   return mEndDay - mStartDay;
}

}