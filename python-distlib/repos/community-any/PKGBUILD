# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=distlib
pkgname='python-distlib'
pkgver=0.3.3
pkgrel=4
pkgdesc="Low-level components of distutils2/packaging"
arch=('any')
url="https://bitbucket.org/pypa/${_pkgname}"
license=('PSF')
depends=('python')
makedepends=('python')
source=("https://files.pythonhosted.org/packages/source/${_pkgname:0:1}/${_pkgname}/${_pkgname}-${pkgver}.zip")
sha256sums=('d982d0751ff6eaaab5e2ec8e691d949ee80eddf01a62eaa96ddb11531fe16b05')
b2sums=('269ec9e8f22c991fea6b81c37d9b527348bd5431fe09b02a7972e3272c379842df0254ae0c9e7283bc1b5a2402d9bd9087e2d1fdd979c1ac3a8b99cfb962c308')

prepare() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    rm distlib/*.exe

}

build() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py build
}

check() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py test || true
}

package() {
    cd "${srcdir}"/${_pkgname}-${pkgver}
    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
}
