# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Jan Koppe <post@jankoppe.de>

pkgname=yarn
pkgver=0.24.5
pkgrel=1
pkgdesc='Fast, reliable, and secure dependency management'
arch=(any)
url='http://yarnpkg.com'
license=('BSD')
depends=('nodejs')
source=("https://github.com/yarnpkg/yarn/releases/download/v$pkgver/yarn-v$pkgver.tar.gz")
sha512sums=('9bc350a64860d6456abee9e3de0b52c429de3a86fabd8ec1483fa4bfe341fc9fdb1eb42d853e2c6310e07fdb4e8fc1c94c7418293cf23b25486d5f6559325483')

package() {
  install -dm755  "$pkgdir"/usr/lib/node_modules/yarn
  cp -R "$srcdir"/dist/* "$pkgdir"/usr/lib/node_modules/yarn

  install -dm755 "$pkgdir"/usr/bin
  ln -s /usr/lib/node_modules/yarn/bin/yarn.js "$pkgdir"/usr/bin/yarn
  ln -s /usr/lib/node_modules/yarn/bin/yarn.js "$pkgdir"/usr/bin/yarnpkg

  install -Dm644 "$srcdir"/dist/LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
