# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Chris Warrick <aur@chriswarrick.com>

pkgname=python-typogrify
_pyname=typogrify
pkgver=2.0.7
pkgrel=10
pkgdesc='filters to make caring about typography on the web a bit easier'
arch=('any')
url='https://github.com/mintchaos/typogrify'
license=('BSD')
depends=('python' 'python-smartypants')
makedepends=('python-setuptools')
source=("https://pypi.python.org/packages/source/${_pyname:0:1}/${_pyname}/${_pyname}-${pkgver}.tar.gz")
md5sums=('63f38f80531996f187d2894cc497ba08')

package() {
  cd "${srcdir}/${_pyname}-${pkgver}"
  python3 setup.py install --root="${pkgdir}/" --optimize=1
  install -D -m644 LICENSE.txt "${pkgdir}/usr/share/licenses/${pkgbase}/LICENSE"
}
# vim:set ts=2 sw=2 et:
