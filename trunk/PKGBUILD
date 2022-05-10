# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: sloppybench <sloppybench@eml.cc>
# Contributor: der_FeniX <derfenix@gmail.com>
# Contributor: Anatol Pomozov <anatol.pomozov@gmail.com>
# Contributor: Gordin <9ordin @t gmail dot com>
# Contributor: Simon Lipp <aur@simon.lipp.name>
# Contributor: Chris Bolton <http://scr.im/chris-kun>
# Contributor: Sergei Lebedev <superbobry at gmail dot com>
# Contributor: flying sheep <flying-sheep@web.de>

pkgname=coffeescript
pkgver=2.7.0
pkgrel=1
pkgdesc='CoffeeScript is a little language that compiles into JavaScript'
arch=('any')
url='https://coffeescript.org'
license=('MIT')
depends=('nodejs')
makedepends=('npm')
provides=("coffee-script=$pkgver")
conflicts=('coffee-script')
replaces=('coffee-script')
source=("https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz")
noextract=("$pkgname-$pkgver.tgz")
sha512sums=('8735a9e93504d9dfe309c37aecbad6d5e8796ffad20ca40aea80fa54c2e582061551415ec604c7f73ddd3588a1cd7e11321cdee454d4b1498e5d5889285411fc')

package() {
  npm install -g --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz

  # Non-deterministic race in npm gives 777 permissions to random directories.
  # See https://github.com/npm/npm/issues/9359 for details.
  chmod -R u=rwX,go=rX "$pkgdir"

  # npm installs package.json owned by build user
  # https://bugs.archlinux.org/task/63396
  chown -R root:root "$pkgdir"

  mkdir -p "$pkgdir/usr/share/licenses/$pkgname"
  ln -s "../../../lib/node_modules/$pkgname/LICENSE" "$pkgdir/usr/share/licenses/$pkgname/"
}
