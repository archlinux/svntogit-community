# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: David Runge <dvzrv@archlinux.org>
# Contributor: David Joaquín Shourabi Porcel <david@djsp.eu>
# Contributor: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=poetry
pkgname=python-poetry
pkgver=1.4.2
pkgrel=2
pkgdesc='Python dependency management and packaging made easy'
arch=(any)
url=https://python-poetry.org
license=(MIT)
_deps=(build
       cachecontrol
       cachy
       cleo
       crashtest
       dulwich
       filelock
       html5lib
       installer
       jsonschema
       keyring
       lockfile
       packaging
       pexpect
       pkginfo
       platformdirs
       poetry-core
       poetry-plugin-export
       pyproject-hooks
       requests
       requests-toolbelt
       shellingham
       tomlkit
       trove-classifiers
       urllib3
       virtualenv)
depends=(
  python
  "${_deps[@]/#/python-}"
)
checkdepends=(
  python-deepdiff  # not mentioned but required
  python-psutil  # for python-pytest-xdist
  python-httpretty
  python-pip  # not mentioned but required
  python-pytest
  python-pytest-mock
  python-pytest-randomly
  python-pytest-xdist
)
optdepends=(
  'python-pip: to use pip with virtual environments'
)
provides=(poetry)
_archive="$_pkgname-$pkgver"
source=("https://github.com/$pkgname/$_pkgname/archive/$pkgver/$_archive.tar.gz")
sha256sums=('8cdbad22dfd11ca9c7e37bcafe18ae931b80e0776adbe6df8d24091bd2b23eff')

prepare() {
  cd "$_archive"
  # Unpin crashtest which we have packaged at 0.4.0
  # https://bugs.archlinux.org/task/75733
  sed -i -e '/^crashtest/s/\^/>=/' pyproject.toml
}

build() {
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  cd "$_archive"
  python -m build -wn

  # install to tmp dir for tests and generate completions
  python -m installer --destdir=test_dir dist/*.whl
  export PYTHONPATH="$PWD/test_dir/$site_packages:$PYTHONPATH"
  export PATH="$PWD/test_dir/usr/bin:$PATH"
  poetry completions bash > poetry.bash
  poetry completions zsh > poetry.zsh
  poetry completions fish > poetry.fish
}

check() {
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")

  cd "$_archive"
  export PYTHONPATH="$PWD/test_dir/$site_packages:$PYTHONPATH"
  pytest -vv tests
}

package() {
  cd "$_archive"
  python -m installer -d "$pkgdir" dist/*.whl
  install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
  install -vDm 644 $_pkgname.bash "$pkgdir/usr/share/bash-completion/completions/$_pkgname"
  install -vDm 644 $_pkgname.zsh "$pkgdir/usr/share/zsh/site-functions/_$_pkgname"
  install -vDm 644 $_pkgname.fish -t "$pkgdir/usr/share/fish/vendor_completions.d/"
}
