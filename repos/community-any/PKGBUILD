# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Jan Koppe <post@jankoppe.de>

pkgname=yarn
pkgver=0.24.4
pkgrel=1
pkgdesc='Fast, reliable, and secure dependency management'
arch=(any)
url='http://yarnpkg.com'
license=('BSD')
depends=('nodejs')
source=("https://github.com/yarnpkg/yarn/releases/download/v$pkgver/yarn-v$pkgver.tar.gz")
sha512sums=('b3ea202dd516520faa671a0f54f608eeac67de0c6099735b985fb8bc54a4d2a66318700a90bf5f0f4640e19836be1b42c3852474b03c7e677f5b5aafc0f5b9e8')

package() {
  install -dm755  "$pkgdir"/usr/lib/node_modules/yarn
  cp -R "$srcdir"/dist/* "$pkgdir"/usr/lib/node_modules/yarn

  install -dm755 "$pkgdir"/usr/bin
  ln -s /usr/lib/node_modules/yarn/bin/yarn.js "$pkgdir"/usr/bin/yarn
  ln -s /usr/lib/node_modules/yarn/bin/yarn.js "$pkgdir"/usr/bin/yarnpkg

  install -Dm644 "$srcdir"/dist/LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
