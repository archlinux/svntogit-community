# Contributor: Alexsandr Pavlov <kidoz at mail dot ru>
pkgname=ruby-rack
gemname=rack
pkgver=1.2.3
pkgrel=1
pkgdesc="Rack provides minimal, modular and adaptable interface for developing web applications in Ruby."
arch=(any)
url="http://rack.rubyforge.org/"
license=('MIT')
depends=(ruby)
source=(http://gems.rubyforge.org/gems/$gemname-$pkgver.gem)
noextract=($gemname-$pkgver.gem)
md5sums=('9cf9dc78d80a8f0b5810c1f53a2ab9d8')

build() {
  cd $srcdir
  # _gemdir is defined inside build() because if ruby[gems] is not installed on the system
  # makepkg will exit with an error when sourcing the PKGBUILD
  local _gemdir="$(ruby -rubygems -e'puts Gem.default_dir')"

  gem install --ignore-dependencies -i "$pkgdir$_gemdir" -n "$pkgdir/usr/bin" $gemname-$pkgver.gem
}
