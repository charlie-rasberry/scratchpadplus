// static.cpp

#include <crow.h>
#include "static.h"

crow::response render(const std::string& p) {
  auto page = crow::mustache::load(p);
  return page.render();
}