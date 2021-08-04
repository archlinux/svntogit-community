# Maintainer: Anatol Pomozov <anatol.pomozov@gmail.com>

_gemname=rake
pkgname=ruby-$_gemname
pkgver=13.0.6
pkgrel=1
pkgdesc='Make-like build tool implemented in Ruby'
provides=(rake)
arch=(any)
url='https://ruby.github.io/rake/'
license=(MIT)
depends=(ruby)
options=(!emptydirs)
source=(https://rubygems.org/downloads/$_gemname-$pkgver.gem)
noextract=($_gemname-$pkgver.gem)
sha512sums=('9dbcd1ef4d93f4853b3da40b29890509bb260e13e5500f5a0502645ce762d6e50ee7dd6bd59d08d135868dab579e10344920ba246079cde7048e3510bd473ea2')

package() {
  local _gemdir="$(ruby -e'puts Gem.default_dir')"
  gem install --ignore-dependencies --no-user-install --no-document -i "$pkgdir/$_gemdir" -n "$pkgdir/usr/bin" $_gemname-$pkgver.gem
  rm "$pkgdir/$_gemdir/cache/$_gemname-$pkgver.gem"
}
