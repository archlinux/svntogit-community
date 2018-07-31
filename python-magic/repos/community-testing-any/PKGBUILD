# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>

pkgbase=python-magic
pkgname=(python-magic python2-magic)
pkgver=5.30
pkgrel=2
pkgdesc="Python bindings to the magic library"
arch=('any')
url='http://darwinsys.com/file/'
makedepends=('python' 'python2' 'python-setuptools' 'python2-setuptools')
license=('custom')
source=("ftp://ftp.astron.com/pub/file/file-${pkgver}.tar.gz")
sha512sums=('473ee57517b449bae0832c17c9db914162c2404f0c669951f13a53f44ae288e6075907bac44fcfa8915f3d9313981a8bc15ea7e9851f584f95988bc76b2f20fc')

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
