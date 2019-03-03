# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>

pkgbase=python-magic
pkgname=(python-magic python2-magic)
pkgver=5.36
pkgrel=1
pkgdesc="Python bindings to the magic library"
arch=('any')
url='http://darwinsys.com/file/'
makedepends=('python' 'python2' 'python-setuptools' 'python2-setuptools')
license=('custom')
source=("ftp://ftp.astron.com/pub/file/file-${pkgver}.tar.gz")
sha512sums=('3ec5e51ffb7a82defa74845a90fbc983f6e169fc116606049bc01ff6e720d340c8abf6eb7a08b9ac1099162a5c02deac3633b07b039d486344c8abd9052ca751')

package_python-magic() {
  depends=('python')

  cd "${srcdir}/file-${pkgver}/python"
  python setup.py install --root="${pkgdir}" --optimize=1
  install -Dm0644 "${srcdir}/file-${pkgver}/COPYING" \
    "${pkgdir}/usr/share/licenses/${pkgname}/COPYING"
}

package_python2-magic() {
  depends=('python2')

  cd "${srcdir}/file-${pkgver}/python"
  python2 setup.py install --root="${pkgdir}" --optimize=1
  install -Dm0644 "${srcdir}/file-${pkgver}/COPYING" \
    "${pkgdir}/usr/share/licenses/${pkgname}/COPYING"
}
