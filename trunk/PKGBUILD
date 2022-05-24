# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Chris Warrick <aur@chriswarrick.com>

pkgname=python-typogrify
_pyname=typogrify
pkgver=2.0.7
pkgrel=13
pkgdesc='filters to make caring about typography on the web a bit easier'
arch=('any')
url='https://github.com/mintchaos/typogrify'
license=('BSD')
depends=('python' 'python-smartypants')
makedepends=('python-setuptools')
source=("https://pypi.python.org/packages/source/${_pyname:0:1}/${_pyname}/${_pyname}-${pkgver}.tar.gz"
        jinja-3.1.patch)
md5sums=('63f38f80531996f187d2894cc497ba08'
         '127f2e8c99733cc24dbe785dd23c34bd')

prepare() {
  cd "${srcdir}/${_pyname}-${pkgver}"
  patch -Np1 -i ../jinja-3.1.patch
}

package() {
  cd "${srcdir}/${_pyname}-${pkgver}"
  python3 setup.py install --root="${pkgdir}/" --optimize=1
  install -D -m644 LICENSE.txt "${pkgdir}/usr/share/licenses/${pkgbase}/LICENSE"
}
# vim:set ts=2 sw=2 et:
