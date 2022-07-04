# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>

pkgname=python-magic
pkgver=5.42
pkgrel=1
pkgdesc="Python bindings to the magic library"
arch=('any')
url='https://darwinsys.com/file/'
depends=('python')
makedepends=('python-setuptools')
license=('custom')
source=("ftp://ftp.astron.com/pub/file/file-${pkgver}.tar.gz")
sha512sums=('33c3c339a561c6cf787cc06a16444a971c62068b01827612c948207a9714107b617bed8148cd67e6280cb1c62ad4dfb1205fb8486ea9c042ce7e19b067d3bb05')

package_python-magic() {
  cd "${srcdir}/file-${pkgver}/python"

  python setup.py install --root="${pkgdir}" --optimize=1

  install -Dm0644 "${srcdir}/file-${pkgver}/COPYING" \
    "${pkgdir}/usr/share/licenses/${pkgname}/COPYING"
}
