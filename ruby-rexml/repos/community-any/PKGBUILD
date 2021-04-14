# Maintainer: Anatol Pomozov <anatol.pomozov@gmail.com>

_gemname=rexml
pkgname=ruby-$_gemname
pkgver=3.2.5
pkgrel=1
pkgdesc='An XML toolkit for Ruby'
arch=(any)
url='https://github.com/ruby/rexml'
license=(BSD-2)
depends=(ruby)
#makedepends=('ruby-rdoc')
options=(!emptydirs)
source=(https://rubygems.org/downloads/$_gemname-$pkgver.gem)
noextract=($_gemname-$pkgver.gem)
sha256sums=('a33c3bf95fda7983ec7f05054f3a985af41dbc25a0339843bd2479e93cabb123')

package() {
  local _gemdir="$(ruby -e'puts Gem.default_dir')"
  gem install --no-document --ignore-dependencies --no-user-install -i "$pkgdir/$_gemdir" -n "$pkgdir/usr/bin" $_gemname-$pkgver.gem
  rm "$pkgdir/$_gemdir/cache/$_gemname-$pkgver.gem"
}
