# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>

pkgname=python-magic
pkgver=5.37
pkgrel=1
pkgdesc="Python bindings to the magic library"
arch=('any')
url='https://darwinsys.com/file/'
depends=('python')
makedepends=('python-setuptools')
license=('custom')
source=("ftp://ftp.astron.com/pub/file/file-${pkgver}.tar.gz")
sha512sums=('bf153c15aebdd00329806231d20f295077b8b99efd0181d01279bcf3734a1718567df38cf75bc929eb8015ac98d29bb4bf1228d7ece8bfdfe14dd976391dd06d')

package_python-magic() {
  cd "${srcdir}/file-${pkgver}/python"

  python setup.py install --root="${pkgdir}" --optimize=1

  install -Dm0644 "${srcdir}/file-${pkgver}/COPYING" \
    "${pkgdir}/usr/share/licenses/${pkgname}/COPYING"
}
