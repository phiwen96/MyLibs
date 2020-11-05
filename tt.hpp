#pragma once




class tt {
public:
      tt();
      tt(tt&&) noexcept;
      tt(const tt&);
      
      ~tt();
      
      friend void swap(tt&, tt&);
      tt& operator=(tt);
      
      friend std::ostream& operator<<(std::ostream&, const tt&);
      
private:
      
};
