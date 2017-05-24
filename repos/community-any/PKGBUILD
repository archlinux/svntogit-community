# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Jan Koppe <post@jankoppe.de>

pkgname=yarn
pkgver=0.24.6
pkgrel=1
pkgdesc='Fast, reliable, and secure dependency management'
arch=(any)
url='http://yarnpkg.com'
license=('BSD')
depends=('nodejs')
source=("https://github.com/yarnpkg/yarn/releases/download/v$pkgver/yarn-v$pkgver.tar.gz")
sha512sums=('470189d4f7c12ef4c25dc29157da034424d5df66eb36a70b02aeedbdd21fd95db93c7119ea94c80c9a78cb08eb09786c9a23e96238a9dd313993763835191717')

package() {
  install -dm755  "$pkgdir"/usr/lib/node_modules/yarn
  cp -R "$srcdir"/dist/* "$pkgdir"/usr/lib/node_modules/yarn

  install -dm755 "$pkgdir"/usr/bin
  ln -s /usr/lib/node_modules/yarn/bin/yarn.js "$pkgdir"/usr/bin/yarn
  ln -s /usr/lib/node_modules/yarn/bin/yarn.js "$pkgdir"/usr/bin/yarnpkg

  install -Dm644 "$srcdir"/dist/LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
