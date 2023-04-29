# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Fabio Volpe <volpefabio@gmail.com>

pkgname=python-sphinx
pkgver=6.2.1
pkgrel=2
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
makedepends=('python-build' 'python-flit-core' 'python-installer')
checkdepends=('cython'
              'imagemagick' 'librsvg'
              'python-filelock'
              'python-html5lib'
              'python-pytest'
              'python-setuptools'
              'texlive-fontsextra' 'texlive-latexextra')
optdepends=('imagemagick: for ext.imgconverter'
            'texlive-latexextra: for generation of PDF documentation')
source=("https://pypi.org/packages/source/S/Sphinx/Sphinx-$pkgver.tar.gz"{,.asc})
sha256sums=('6d56a34697bb749ffa0152feafc4b19836c755d90a7c59b72bc7dfd371b9cc6b'
            'SKIP')
b2sums=('19b1fbffc5f44c557f4309c35ff4587cb7eaa7d5157c1a6d5d33474c1a91d15de5e53076e9ca7d7097ee13035e2fd8fe623368236ed28a9d1ce389ff58a8f6ba'
        'SKIP')
validpgpkeys=('8A11B79A5D0D749A66F0A030102C2C17498D6B9E'  # Takeshi KOMIYA <i.tkomiya@gmail.com>
              'E9BEABB07E7B9CC3F56E62C91425F8CE5EBA0E07'  # Takayuki Shimizukawa <shimizukawa@gmail.com>
              'D3549119BD51B4AFE643E59752C8F72A61F0FB52') # Adam Turner <9087854+aa-turner@users.noreply.github.com>

build() {
  cd Sphinx-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd Sphinx-$pkgver
  LC_ALL="en_US.UTF-8" python -X dev -X warn_default_encoding -m pytest -v
}

package() {
  cd Sphinx-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/sphinx-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
