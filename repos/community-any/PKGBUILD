# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Chris Warrick <aur@chriswarrick.com>

pkgbase=python-typogrify
pkgname=('python-typogrify' 'python2-typogrify')
_pyname=typogrify
pkgver=2.0.7
pkgrel=5
pkgdesc='Filters to enhance web typography'
arch=('any')
url='https://github.com/mintchaos/typogrify'
license=('BSD')
makedepends=('python' 'python2' 'python-setuptools' 'python2-setuptools'
             'python-smartypants' 'python2-smartypants')
source=("https://pypi.python.org/packages/source/${_pyname:0:1}/${_pyname}/${_pyname}-${pkgver}.tar.gz")
md5sums=('63f38f80531996f187d2894cc497ba08')

prepare() {
  cd "${srcdir}/${_pyname}-${pkgver}"
  cp -r "${srcdir}/${_pyname}-${pkgver}" "${srcdir}/${_pyname}-${pkgver}-py2"
}

package_python-typogrify() {
  depends=('python' 'python-smartypants')
  cd "${srcdir}/${_pyname}-${pkgver}"
  python3 setup.py install --root="${pkgdir}/" --optimize=1
  install -D -m644 LICENSE.txt "${pkgdir}/usr/share/licenses/${pkgbase}/LICENSE"
}

package_python2-typogrify() {
  depends=('python2' 'python2-smartypants')
  cd "${srcdir}/${_pyname}-${pkgver}-py2"
  # fixing python2 shebang
  sed -i 's|#!/usr/bin/env python|#!/usr/bin/env python2|' typogrify/packages/titlecase/__init__.py
  sed -i 's|#!/usr/bin/env python|#!/usr/bin/env python2|' typogrify/packages/titlecase/tests.py
  python2 setup.py install --root="${pkgdir}/" --optimize=1
  install -D -m644 LICENSE.txt "${pkgdir}/usr/share/licenses/python2-typogrify/LICENSE"
}

# vim:set ts=2 sw=2 et:
