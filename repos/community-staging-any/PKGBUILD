# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>

pkgbase=python-magic
pkgname=(python-magic python2-magic)
pkgver=5.29
pkgrel=2
pkgdesc="Python bindings to the magic library"
arch=('any')
url='http://darwinsys.com/file/'
makedepends=('python' 'python2' 'python-setuptools' 'python2-setuptools')
license=('custom')
source=("ftp://ftp.astron.com/pub/file/file-${pkgver}.tar.gz")
md5sums=('b7b57b36b577c9cede2f2d1342203302')

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
