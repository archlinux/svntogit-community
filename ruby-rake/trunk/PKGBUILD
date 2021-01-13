# Maintainer: Anatol Pomozov <anatol.pomozov@gmail.com>

_gemname=rake
pkgname=ruby-$_gemname
pkgver=13.0.2
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
sha512sums=('8331ebb726bd681462aa59507fb7d1f472a0f7ca11188ed5d0d5a8d9badad88bac24dcf7df1b3d57d357fa4effee4becbe8491f9b20326c006cf378611c7141e')

package() {
  local _gemdir="$(ruby -e'puts Gem.default_dir')"
  gem install --ignore-dependencies --no-user-install --no-document -i "$pkgdir/$_gemdir" -n "$pkgdir/usr/bin" $_gemname-$pkgver.gem
  rm "$pkgdir/$_gemdir/cache/$_gemname-$pkgver.gem"
}
