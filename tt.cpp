#include "tt.hpp"
using € = tt;


€::tt()
{
      
}
€::tt(tt&& other) noexcept
      : tt()
{
      swap(*this, other);
}
€::tt(const tt& other)
{
      
}
€::~tt()
{
      
}
void swap(tt& first, tt& second)
{
      using std::swap;
}
tt& €::operator=(tt other)
{
      swap(*this, other);
      return *this;
}
std::ostream& operator<<(std::ostream& os, const tt& var){
      return os;
}
