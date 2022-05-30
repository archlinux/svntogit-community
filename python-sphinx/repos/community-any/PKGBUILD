# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Fabio Volpe <volpefabio@gmail.com>

pkgname=python-sphinx
pkgver=5.0.0
pkgrel=1
pkgdesc='Python documentation generator'
arch=('any')
url=http://www.sphinx-doc.org/
license=('BSD')
depends=('python-babel'
         'python-docutils'
         'python-imagesize'
         'python-jinja'
         'python-packaging'
         'python-pygments'
         'python-requests'
         'python-snowballstemmer'
         'python-sphinx-alabaster-theme'
         'python-sphinxcontrib-'{{apple,dev,html}help,jsmath,qthelp,serializinghtml})
makedepends=('python-setuptools')
checkdepends=('cython'
              'imagemagick' 'librsvg'
              'python-html5lib'
              'python-pytest'
              'texlive-fontsextra' 'texlive-latexextra')
optdepends=('imagemagick: for ext.imgconverter'
            'texlive-latexextra: for generation of PDF documentation')
source=("https://pypi.org/packages/source/S/Sphinx/Sphinx-$pkgver.tar.gz"{,.asc}
        'sphinx-fix_testcase.patch::https://github.com/sphinx-doc/sphinx/commit/a904ab563a14ee5891551fdecf0d66d26774979f.patch')
sha256sums=('464d9c1bd5613bcebe76b46658763f3f3dbb184da7406e632a84596d3cd8ee90'
            'SKIP'
            '9d6c995585945a0a3f996c3c965a4018cb052aa91b0037cd5539212dab1c3cbd')
b2sums=('95f2b85c7de6d900922730c3e431259e2333b3fe27e25cbe35e9584ccf1ac3442ca0949018e64ca8481e60f2298b46f6a77523a7a67e6aafe7492b62ff97aa70'
        'SKIP'
        'bcb94aefbdbb418b14bdc320c0fd796633c34a1f23f0934a0b78a555e460906de86496f3f85a1304d9adaf6c3914f3cc57a20ab837aa8f23362f5779833f4ce6')
validpgpkeys=('8A11B79A5D0D749A66F0A030102C2C17498D6B9E'  # Takeshi KOMIYA <i.tkomiya@gmail.com>
              'E9BEABB07E7B9CC3F56E62C91425F8CE5EBA0E07') # Takayuki Shimizukawa <shimizukawa@gmail.com>

prepare() {
  cd Sphinx-$pkgver
  patch --forward --strip=1 --input=../sphinx-fix_testcase.patch
}

build() {
  cd Sphinx-$pkgver
  make build
}

check() {
  cd Sphinx-$pkgver
  LC_ALL="en_US.UTF-8" make test
}

package() {
  cd Sphinx-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:
