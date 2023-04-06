# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Felix Yan <felixonmars@archlinux.org>
# Contributor: NicoHood <archlinux {cat} nicohood {dog} de>
# Contributor: Carl George < arch at cgtx dot us >

_name=smmap
pkgname=python-smmap
pkgver=5.0.0
pkgrel=4
epoch=1
pkgdesc="A pure git implementation of a sliding window memory map manager"
arch=('any')
url="https://github.com/gitpython-developers/smmap"
license=('BSD')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://pypi.org/packages/source/s/${_name}/${_name}-${pkgver}.tar.gz"{,.asc})
sha512sums=('03ae478bc83d02416f57bb3f6afc9c80bcb2d4249f3169390ac139b88be94258463dee7744fdf0fd54a7cfe109795a110c43f2b81ffd8546601de274667d353d'
            'SKIP')
b2sums=('2ff55ff412b10fe6c431df5f1589deb9f6f1c3277ee1ac651513e302d31b4f7ff986bfc548c5fefd66775f0eb7aef11dd8f2821f0e50a2e76d9bfcfaa9c047bd'
        'SKIP')
validpgpkeys=('27C50E7F590947D7273A741E85194C08421980C9') # Sebastian Thiel (In Rust I trust!) <byronimo@gmail.com>

prepare() {
  mv -v "${_name}-${pkgver}" "${pkgname}-${pkgver}"
}

build() {
  cd "${pkgname}-${pkgver}"
  python setup.py build
}

check() {
  cd "${pkgname}-${pkgver}"
  pytest -v
}

package() {
  cd "${pkgname}-${pkgver}"
  python setup.py install --optimize=1 --root="${pkgdir}"
  install -vDm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}/"
  install -vDm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}/"
}
